inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
	object *ulist, *ilist;
	int i, j;
	int k, num;
	string file;
	
	if (! arg)
		return notify_fail ("╓╕┴ю╕ё╩╜ whohas <id>\n");
    
    if( wiz_level(me) < wiz_level("(wizard)") )
		return notify_fail("─у╡─╬╫╩ж╡╚╝╢╠л╡═гм├╗╙╨╩╣╙├╒т╕Ў╓╕┴ю╡─╚и┴жбг\n");
//        ulist = filter_array(objects(), (: userp($1) :));
 	ulist = objects();
	i = sizeof(ulist);
	k = 0;
	while (i--) {
		if (! present (arg,ulist[i]))
			continue;
//		if (sscanf(file_name(ulist[i]),"%s#%d",file, num)!= 2)
//			continue;
		k = k+1;
		write ("  "+ulist[i]->query("name")+ "ги" + ulist[i]->query("id") 
				+ "гй	(" + file_name(ulist[i]) +"гй :\n");
		ilist = all_inventory(ulist[i]);
		j = sizeof(ilist);
		while (j--) {
			object ob = ilist[j];
			string *ids = ob->parse_command_id_list();
			if (member_array(arg, ids) == -1)
				continue;
			write ("               "+ob->short());
		}
		write ("\n");
	}
	if (k == 0) write ("├╗╙╨╚╦╨п┤°─у╥к╤░╒╥╡─╬я╞╖бг\n");
	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	whohave <id>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┐╔┴╨│Ў─┐╟░╨п┤°─│╕Ў╬я╞╖╡─═ц╝╥/╔·╬я╡╚бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
);
        return 1;
}
