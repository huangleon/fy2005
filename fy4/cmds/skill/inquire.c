// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;

string getdam(object me, object obj);
string *skill_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��������" NOR,
	HIB "������" NOR,
	HIB "�������" NOR,
	CYN "�������" NOR,
	CYN "����似" NOR,
	CYN "�����뻯" NOR,
	HIC "�Ƿ��켫" NOR,
	HIC "һ����ʦ" NOR,
	HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "�����ž�" NOR,
	HIB "��֪һ��" NOR,
	HIB "������" NOR,
	HIB "����С��" NOR,
	CYN "�������" NOR,
	CYN "��Ȼ���" NOR,
	CYN "��Ȼ��ͨ" NOR,
	HIC "������˫" NOR,
	HIC "������" NOR,
	HIW "��ɲ�" NOR
});
mapping area_name = ([ 
		"baiyun"	:	"���Ƴ�",
		"bat"		:	"����",
		"bashan"	: 	"��ɽ",
		"bawang"	:	"������",
		"biancheng"	:	"�߳�",
		"cave"		:   "���Ƶ��³�",
		"chenxiang"	:	"������",
		"chuenyu"	:	"���ɱ�",
		"cyan"		: 	"��ϼɽ",
		"daimiao"	:	"���",
		"death"		:	"���Ź�",
		"eastcoast"	: 	"����",
		"eren"		:    "���˹�",
		"eren2"		:    "���˹�",
		"fy"		:	"���Ƴ�",
		"fugui"		:    "����ɽׯ",
		"fycycle"	:  	"�������",
		"fywall"	:   "���Ƴ�",
		"ghost"		:    "����ɽׯ",
		"guanwai"	:  	"����",
		"guanyin"	:  	"���",
		"huangshan"	:	"��ɽ",
		"huashan"	:  	"��ɽ",
		"jinan"		:    "����",
		"laowu"		:    "����",
		"libie"		:    "����С��",
		"loulan"	:   "¥��",
		"manglin"	:  	"ç��",
		"oldpine"	:  	"����կ",
		"palace"	:   "������",
		"qianfo"	:   "ǧ��ɽ",
		"qianjin"	:  	"ǧ��¥",
		"qingping"	: 	"��ƽɽׯ",
		"quicksand"	:	"��ɳĮ",
		"resort"	:   "��ѩɽׯ",
		"shaolin"	:  	"������",
		"shenshui"	: 	"��ˮ��",
		"songshan"	: 	"��ɽ",
		"taiping"	:  	"̫ƽ��",
		"taishan"	:  	"̩ɽ",
		"taoguan"	:  	"��Դ",
		"taoyuan"	:  	"�����",
		"tieflag"	:  	"�����",
		"wanmei"	:   "��÷ɽׯ",
		"wolfmount"	:	"��ɽ",
		"wudang"	:   "�䵱",
		"xiangsi"	: 	"��˼��",
		"xinjiang"	: 	"�½�",
		"yingou"	:   "�����ķ�",
		"zhaoze"	:	"�����",
		"zangbei"	:	"�ر�",
]);                             
string *heavy_level_desc= ({
	"����",
	"����",
	"����",
	"����",
	"����",
	"����"	
});



string skill_level(string, int);
int main(object me, string arg)
{                               
	object ob, man, *all    ;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp, skill;             
	int i, cost;            
	object room;            
	string location,*area,line;
	mapping my;        
	                        
	                        
        seteuid(getuid());      
        skill=me->query_skill("begging",1);
        
                         
//	check requirement            
	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}                       
                                
        if (me->query("class")!="beggar")
		return notify_fail("ֻ��ؤ����Ӳ��ܴ�̽���˵���Ϣ��\n");
	
	if (skill<50)
		return notify_fail("�������֮��������������50��\n");
	
	if ( !objectp(man) )    
		return notify_fail("��Χû���ܰ���ȥ��̽���˵���Ϣ��\n");

	if (arg==("monster nian"))
		return notify_fail("�NPC�޷�������\n");

	if ( !arg )             
		return notify_fail("��Ҫ����˭����Ϣ��\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) 
		return notify_fail("��Ҫ����˭����Ϣ��\n");
	if ( wizardp(ob))
			return notify_fail("��Ҫ����˭����Ϣ��\n");
	if ( ob == me )         
		return notify_fail("������ָ��������\n");
        if ( present(ob, environment(me)) )
                return notify_fail("��Ҫ�������˾��������\n");
	cost = me->query("max_gin")/(me->query_skill("begging",1)/10 + 1);
	if ( me->query("gin") <= cost )
		return notify_fail("������̫���ˣ��޷�ȥ�������˵���Ϣ��\n");
	if (me->is_busy())
		return notify_fail("��������æ��\n");
		
//	start inquire
	tell_object(me, "�������" + man->name() + "��������" + ob->name() + "����Ϣ��\n\n");
	message("vision", "ֻ��" + me->name() + "��ͷ�Ӷ��ظ�" + man->name() + "˵�Ż��������ڴ���Щʲô��\n\n", 
		environment(me), ({ me, man }) );
	sp = me->query_skill("begging")*10 + me->query("kar")*5 + me->query("gin") + man->query("gin");
	dp = ob->query("kar")*10 + ob->query("gin")*3;
		me->receive_damage("gin", cost );
	if ( random(sp) < random(dp) || wizardp(ob))
		return notify_fail( man->name() + "ҡ��ҡͷ��˵���������ҿɲ������"
		 	+ RANK_D->query_respect(me) + "����ȥ����˴���һ�°ɣ�\n");

	write(YEL"\n"+man->name()+YEL"���ĵظ����㣺\n\n"NOR);
//	basic information inquiry
	my = ob->query_entire_dbase();
	
	line = ob->query("title")?ob->query("title"):"";
	line += sprintf("    %s��%s��%s��%s�꣬",
		ob->query("name"),
		(ob->query("national")? ob->query("national") : "������"),
		ob->query("gender"),
		chinese_number(ob->query("age")));
	
	if ( my["marry"] || my["divorced"]) {
        	if (my["marry"]) {
        		line += (ob->query("gender") == "Ů��" ? "����":"Ȣ��")
        			+ my["marry_name"]+ "(" + my["marry"] +")��\n";  		
        	}
        	else
        		line += "��" + (ob->query("gender") == "Ů��" ? "�Ѿӡ�":"���ӡ�");
	}
	else
		line += "��δ���䡣";
		
	if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] )
                        line += sprintf("��ʦ%s��",
                                my["family"]["master_name"] );
        }
        
        if (userp(ob)) {
        if (my["PKS"]>80) line += "\n"+ob->name()+"�׺ݼ�����ɱ���ԡ�";
        	else if (my["PKS"]>40) line+="\n"+ob->name()+"���ºö�������������";
        	else if (my["PKS"]>10) line+="\n"+ob->name()+"ż���Ӽ���ȴ�޶��С�";
        		else line += "\n"+ob->name()+"����������������á�";
        } else line +="\n";
        	
	write (line);


//	skill inquiry	
	
	if (skill<100) 
		write ("��̽�������˵��书���硣\n");
	else {	
		skl = ob->query_skills();
		if(!sizeof(skl)) {
			write("���˳���"+getdam(me,ob)+"��ʲô�����ᣡ\n");
		} else {
			write("���˳���"+getdam(me,ob)+"�����ó��ļ���֮һ�ǣ�\n");
			sname  = sort_array( keys(skl), (: strcmp :) );
			map = ob->query_skill_map();
			if( mapp(map) ) mapped = values(map);
			if( !mapped ) mapped = ({});
			lrn = ob->query_learned();
			if( !mapp(lrn) ) lrn = ([]);
			i = random(sizeof(skl));
			printf("%s%s%-40s" NOR " - %-10s \n", 
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
				(member_array(sname[i], mapped)==-1? "  ": "��"),
				SKILL_D(sname[i])->name() + " (" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			);
			write("\n");
		}
	}
	
//	location inquiry, for player, it's area only
	
	if (skill<150) 
		write("��̽�������˾�����û�ĵ�����\n\n\n");
	else {
		room=environment(ob);
		area=keys(area_name);
		if (!room) 
			write("���������������ҵ�"+ob->name()+"��\n\n\n");
		else {
			location=domain_file(file_name(room));
			if (member_array(location,area)==-1)	
				write("���������������ҵ�"+ob->name()+"��\n\n\n");
			else if (skill<250)
				write(ob->name()+"�������������"+area_name[location]+"һ���߶���\n\n\n");
			else 	
				write(ob->name()+"�����������"+area_name[location]+room->query("short")+"���֡�\n\n\n");
		}	
	}
	me -> perform_busy(2);
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 20;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

string getdam(object me, object obj) {	
	int str, level, max_str, max_level;
	
	max_str = 120;
	max_level = sizeof(heavy_level_desc) - 1;
	
	str = obj->query_str();
	level = str * max_level / max_str;
	level = level > max_level ? max_level : level; 
	return heavy_level_desc[level];
}


int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	inquire <ĳ��>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ���������������˵���Ϣ��������Ϊؤ�����ר�ã�
����ѧϰ����֮�������ܵȼ�Խ�ߣ��õ�����Ϣ��Խ�࣬��
���˽�Է����������书��ǳ���������࣬��������֪����
���Ĵ���λ�á���������Ҫ����������֮����

[0;1;37m����������������������������������������������������������������[0m   

HELP
    );
    return 1;
}
