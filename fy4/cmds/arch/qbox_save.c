// Silencer@fengyun workgroup	June.2005

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
	object *ob;
	int i;
	
	ob = users();	
	for (i=0;i<sizeof(ob);i++) {
		if (!ob[i] || !objectp(ob[i])) continue;
		if (!(i%10))
			reset_eval_cost();
		ob[i]->ccommand("qsave");
	}
	write("╣▓╝╞"+ sizeof(ob)+"╕Ў╢╘╧єгм╕№╨┬═ъ▒╧бг\n");
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	qbox_save[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m  

╒т╕Ў╓╕┴ю╜л┴ю╦∙╙╨═ц╝╥╓┤╨╨гёгєгсгЎгх├№┴югм░╤╨■┴щ╙ё║╨╜╗╗╣╕°Ё╨Ё─╕єбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
HELP
    );
    return 1;
}
