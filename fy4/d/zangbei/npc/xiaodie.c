// Silencer@fengyun workgroup	June.2005, 
// No more skills between couples... xiaodie becomes a memeory.

#include <ansi.h>
inherit NPC;
inherit INQUIRY_MSG;

int check_other(object me);
int zero_skill(object me, string arg);

void create()
{
    	set_name("С��",({"xiaodie","xiao die"}));
//	set("title",HIR""NOR);
   	set("long","
С����Ů���Ӻ��ر������ú����������ˣ�������Ů����ͨ����֪��������
��ô����������ʱ�����������ѱ�����һ�㡣С��ȴ��ͬ����������Լ�����
�ǳ���ȫ���ں���������Ⱥ�У�Ҳ��Ц��������Ц��Ҳ�ͱ�����ȫ��ͬ����
�ۺͶ�������һ������������һ����վ�ں�������Ŀ�Ұ�С�������������
��ס��ӵ��������������\n");
     	
     	set("gender","Ů��");
     	     	
    	set("age",20); 	 	
    	set("int",52);
    	set("per",100);
    	set("cps",20);
    	set("str",10);
    	
    	set("combat_exp",10000);  
    	set("attitude", "friendly");
    	
    	set("skill_public",1);

/*	set("inquiry", ([
 		"ѧ����":	CYN"�ţ�����Խ���Щ����teach xiaodie �������ƣ���
��Ҳ�������ҷ�����Щ����teach xiaodie abandon����\n"NOR,
   	]));*/
   	
    	set("chat_chance",1);
    	set("chat_msg",({
		"С���۾����ɸ�����������������������ӹ���ʱ�򣬼�ʱ���˸�Ը����\n",
		"С���������һ���������û�л������ô��������\n",
//		"С��˵��Ů����ѧ����̫�ã������������һ������ҵĻ�����Ҳ����ѧһЩ��\n",
    	}) );    	    	
    	
	setup();
    	carry_object(__DIR__"obj/redcloak")->wear();
    
}


void init() {
	add_action("do_hug",({"hug","kiss","kiss2",}));
//	add_action("do_teach","teach");
}


int recognize_apprentice(object ob)
{
    	if (!this_player()->query("m_success/����¥")) {
    		message_vision("С�����ȵ�˵����������ô�����ģ����뿪�ɡ���\n",this_player());
    		return 0;
    	}
    	if(this_object()->query("spouse")==this_player())
        	return 1;
	return 0;
}

/*
int do_teach(string arg){
	
	object me;
	object xiaodie;
	string err,who,skill_name;
	string *x_skill;
	int i;
	
	me=this_player();
	xiaodie=this_object();
	
	if (!this_player()->query("m_success/����¥")) {
    		message_vision("С�����ȵ�˵����������ô�����ģ����뿪�ɡ���\n",this_player());
    		return 1;
    	}
	if (sscanf(arg,"%s %s",who,skill_name)!=2)
		return notify_fail("��ʽ��teach xiaodie ��������\n");
	
	if (who!="xiaodie")
		return notify_fail("��ʽ��teach xiaodie ��������\n");
		
	if( !skill_name || skill_name=="" ) return notify_fail("��Ҫ��С����һ���书��\n");

	if (skill_name== "abandon") {
		if (xiaodie->query_skills())
			x_skill = keys(xiaodie->query_skills());
		
		if (sizeof(x_skill)>0) {
			for (i=0;i<sizeof(x_skill);i++) {
				xiaodie->delete_skill(x_skill[i]);
				me->delete("xiaodie/"+x_skill[i]);
				tell_object(me,"С��������"+SKILL_D(x_skill[i])->name()+"��\n");
			}
		}
		message_vision("С��˵���ţ���Щ����������ѧ����ģ���ѧ�Ͳ�ѧ�ɡ�\n",xiaodie);
		return 1;
	}
	
	
	if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) {
		return notify_fail("��" + skill_name + "���������ּ�����\n");	
	}
	
        seteuid(getuid());
        err = catch( call_other(SKILL_D(skill_name)+".c", "???") );
        if (err)
                printf( "��������\n%s\n", err );
	
	if( !me->query_skill(skill_name,1) && !zero_skill(me,skill_name))
		return notify_fail("�㲢û��ѧ�������书��\n");
	
	if (sizeof(xiaodie->query_skills())>2)
		return notify_fail("С�����ֻ��ѧ���Ź���\n");
	
	if (check_other(me))
		return notify_fail("С������ͷ˵����������ˣ��Ҳ����赶Ūǹ�ġ�\n");
		
	message_vision("$N��С��Я���֣����������ţ�˵�����Ļ���\n",me);
	tell_object(me,"���"+SKILL_D(skill_name)->name()+"���ľ����ڸ���С����\n");
	xiaodie->set_skill(skill_name,me->query_skill(skill_name,1));
	me->set("xiaodie/"+skill_name,me->query_skill(skill_name,1));
	return 1;
	
}

*/

int do_hug (string arg){
	
	object xiaodie;
	
	if (arg != "С��" && arg != "xiao die" && arg != "xiaodie")  return 0;
	if (!xiaodie=present("xiao die",environment(this_object()))) return 0;
	if (check_other(this_player())) {
		tell_object(this_player(),"�������ڳ�����һ����ɡ�\n");
		return 1;
	}
	call_out("event1",1,this_player(),0);
	return 1;
}



string *event1_msg=	({
	MAG"\n    �������ӵ����С�����������������˵���ò��������Ȼ�Ķ���\n"NOR,
	
	MAG"    С����������Ļ�����к������������Ͻ������ޡ�\n"NOR,

 	MAG"    �����������С���ǳ������㷢����һ�������������Ĳ����\n"NOR,

    	MAG"    С��ֻ���û���������ģ���Ȼ����ҡ��ۣ���������\n"NOR,
	
	MAG"    һ�����������������ĵ���ð����������Ը��������������񳯣���\n"NOR,

	MAG"    С���ճյؿ����㣬�ճյ��ظ��š���Ը��������������񳯣���\n"NOR,

    	MAG"    ������жȥ��С���Ĵ�춷��ӵ������׹⻬�ļ�����\n"NOR,

	MAG"    С������Ļ���΢΢�ز����������Ǹ�������ӳ���˵ĺ��߲ݡ�\n"NOR,

	MAG"    ���ǳ������Ҹ��ĺ����������������\n"NOR,
    	
    	MAG"    ������������������������������\n"NOR,
    	
    	MAG"    ��������������������������\n"NOR,
    	
		MAG"    ��Ը��������������񳯣�\n"NOR,
    	
    	MAG"    ������������������\n"NOR,
    	
    	MAG"    ����������\n"NOR,
    	
    	MAG"    ������\n"NOR,

});


void event1(object me, int count)
{
	mapping data;
	
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	if (check_other(me)) {
		tell_object(me,"�������ڳ�����һ����ɡ�\n");
		return;
	}
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		tell_object(me,MAG"    �����ã���������һЦ��վ��������\n\n"NOR);
		
		if (REWARD_D->riddle_check(me,"��԰����")==14) {	 // incase some wiz summoned you in :D
			REWARD_D->riddle_done(me,"��԰����",100,1);
			data = ([
				"name":		"��԰����",
				"target":	me,
				"att_1":	"cps",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);	
		}		
		return;
	}
	else call_out("event1",2,me,count);
	return ;
}


int check_other(object me) {
	
	object *env;
	int i;
	
	env=all_inventory(environment(me));
	for (i=0;i<sizeof(env);i++) {
		if (env[i]!=me && userp(env[i])) return 1;
	}
	return 0;
}
	
/*	
	
int zero_skill(object me, string arg) {
	mapping learned_skill_points;
	
	learned_skill_points=me->query_learned();
	if (!learned_skill_points[arg]) return 0;
	return 1;
}	


*/