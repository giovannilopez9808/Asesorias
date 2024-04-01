from argparse import ArgumentParser
from os.path import join
import pandas as pd


def clean_answers(data: pd.DataFrame):
    data = data.drop(columns="Marca temporal")
    return data


parser = ArgumentParser()
parser.add_argument(
    "--test",
    required=True,
    type=str
)
parser.add_argument(
    "--part",
    required=True,
    type=str,
)
args = parser.parse_args()
if args.test != "0":
    filename = f"Prueba{args.test}_{args.part}_answers.csv"
    print(filename)
else:
    filename = "PAA_1_answers.csv"
parameters = {
    "path data": "Answers",
    "file form": "Prueba.csv",
    "file answers": filename,
}
columns = ["Right", "Wrong", "NA"]
answers_form = join(
    parameters["file form"]
)
answers_form = pd.read_csv(parameters["file form"],
                           index_col=1)
answers = join(
    parameters["path data"],
    parameters["file answers"]
)
answers = pd.read_csv(
    answers,
    index_col=0
)
answers_form = answers_form.fillna("NA")
answers = answers.fillna("NA")
answers_form = clean_answers(answers_form)
questions = list(answers.index)
data_per_person = pd.DataFrame(index=answers_form.index,
                               data=0,
                               columns=columns)
data_per_person_per_question = pd.DataFrame(index=questions,
                                            columns=answers_form.index)
data_per_question = pd.DataFrame(index=questions, data=0, columns=columns)
for question in questions:
    for person in answers_form.index:
        if (answers["Answer"][question] == answers_form[question][person]):
            answer = "Right"
        elif (answers_form[question][person] == "NA"):
            answer = "NA"
        else:
            answer = "Wrong"
        data_per_person[answer][person] += 1
        data_per_person_per_question[person][question] = answer
        data_per_question[answer][question] += 1

for person in answers_form.index:
    print(pd.DataFrame(data_per_person.transpose()[person]))
    print(data_per_person_per_question[person])
print(data_per_question)
