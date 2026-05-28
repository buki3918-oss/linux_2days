import pandas as pd

df = pd.read_csv("students.csv")

print("=== 原始資料 ===")
print(df)

print("\n=== 前 3 筆資料 ===")
print(df.head(3))

print("\n=== 平均分數 ===")
print(df["score"].mean())

print("\n=== 只看 CS 系學生 ===")
cs_students = df[df["department"] == "CS"]
print(cs_students)
