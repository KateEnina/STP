using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace PhoneBook {
	public class PhoneBook {
		public SortedDictionary<String, List<String>> dict;


		public PhoneBook() {
            int ch = 0;
			dict = new SortedDictionary<String, List<String>>();
			if (File.Exists("PhoneBook.txt")) {
				try {
					using (StreamReader sr = new StreamReader("PhoneBook.txt", Encoding.Default)) {
						String line;
                        
                        while ((line = sr.ReadLine()) != null) {
                            
                            List<String> listOfNewStrings;
							listOfNewStrings = line.Split(new String[] { "/" }, StringSplitOptions.RemoveEmptyEntries).ToList();
							dict.Add(listOfNewStrings.ElementAt(0), listOfNewStrings.Skip(1).ToList());
                            

                        }
                        
                        //MessageBox.Show("Не удаётся прочитать файл:", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
				} catch (Exception ex) {
                   Debug.WriteLine("Ошибка при чтении файла: " + ex.ToString());
				}
			} else {
				File.Open("PhoneBook.txt", FileMode.Create);
			}
		}

		public bool Add(String name, String phone) {
			Regex nameRegex = new Regex("[А-Я][а-я]+(-[А-Я][а-я]+)? [А-Я][а-я]+(-[А-Я][а-я]+)? [А-Я][а-я]+(-[А-Я][а-я]+)?");
			Regex phoneRegex = new Regex("\\d{1,2}-\\d{3}-\\d{3}-\\d{2}-\\d{2}");
			if (!(nameRegex.IsMatch(name) && phoneRegex.IsMatch(phone))) {
				MessageBox.Show("Некорректный формат данных! Правильный формат: " + Environment.NewLine + "Имя: \"Фамилия Имя Отчество\"" + Environment.NewLine + "Номер телефона: \"*-***-***-**-**\"", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return false;
			}
			foreach (KeyValuePair<String, List<String>> kvp in dict) {
				if (kvp.Value.Contains(phone)) {
					DialogResult answer = MessageBox.Show("Записанный вами номер уже есть в базе у абонента: " + Environment.NewLine + kvp.Key + Environment.NewLine + "Хотите продолжить?", "Предупреждение", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
					if (answer == DialogResult.Yes)
						break;
					else
						return false;
				}
			}
			if (dict.ContainsKey(name)) {
				if (dict[name].Contains(phone)) {
					MessageBox.Show("Данный контакт уже существует в базе!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
					return false;
				} else
					dict[name].Add(phone);
			} else
				dict.Add(name, new List<string>() { phone });
			return true;
		}

		public bool Replace(String name, String oldPhone, String newPhone) {
			if (!dict[name].Contains(oldPhone)) {
				MessageBox.Show("Абонента с таким номер телефона не существует!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return false;
			}
			dict[name][dict[name].FindIndex(x => x == oldPhone)] = newPhone;
			return true;
		}

		public bool DelPhone(String name, String phone, bool debugInf) {
			if (!dict[name].Contains(phone)) {
				if (debugInf)
					MessageBox.Show("Абонента с таким номер телефона не существует!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return false;
			}
			dict[name].Remove(phone);
			if (dict[name].Count == 0) {
				if (debugInf)
					MessageBox.Show("Абонент удалён.", "Предупреждение", MessageBoxButtons.OK, MessageBoxIcon.Warning);
				dict.Remove(name);
			}
			return true;
		}

		public void Save() {
			try {
				using (FileStream fs = new FileStream("PhoneBook.txt", FileMode.Create)) {
					StreamWriter sw = new StreamWriter(fs, Encoding.Unicode);
					StringBuilder output = new StringBuilder();
					foreach (KeyValuePair<String, List<String>> kvp in dict) {
						output.Append(kvp.Key + "/");
						foreach (string str in kvp.Value)
							output.Append(str + "/");
						sw.Write(output + Environment.NewLine);
                        output.Clear();
					}
                    sw.Close();
				}
			} catch (Exception ex) {
				Debug.WriteLine("Не удаётся созранить файл " + ex.ToString());
			}
		}

		public void Load() {
			if (File.Exists("PhoneBook.txt")) {
				try {
					using (StreamReader sr = new StreamReader("PhoneBook.txt", Encoding.Unicode)) {
						String line;
						while ((line = sr.ReadLine()) != null) {
                            List<String> listOfNewStrings;
							listOfNewStrings = line.Split(new String[] { "/" }, StringSplitOptions.RemoveEmptyEntries).ToList();
                            //dict.Add(listOfNewStrings.ElementAt(0), listOfNewStrings.Skip(1).ToList());
                            this.Add(listOfNewStrings.ElementAt(0),  string.Join("",listOfNewStrings.Skip(1).ToList() ));
                        }
					}
				} catch (Exception ex) {
					Debug.WriteLine("Ошибка при чтении файла: " + ex.ToString());
                    MessageBox.Show("Не удаётся прочитать файл:", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
			} else {
				File.Open("PhoneBook.txt", FileMode.Create);
			}
		}

		public void Clear() {
			dict.Clear();
		}
	}
}
