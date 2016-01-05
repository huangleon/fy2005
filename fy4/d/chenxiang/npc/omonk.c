#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�Ϻ���", ({ "old monk","monk" }) );
	set("gender", "����" );
	set("age", 57);
	set("long", "�Ϻ�����ɫ����Ŀ¶���⣬��ϧ�������°��ϳ��˸������ӡ�\n");
	set("combat_exp", 100000);
	    set("inquiry", ([
        	"����" : 	"����û�е���������������򼸿�����Ȼ����ʯ���ӹ��\n",
        	"yubotao" : "����û�е���������������򼸿�����Ȼ����ʯ���ӹ��\n",
        	"��ʯ��" : 	"��ʯ��������������ģ��������ϵ����Ĵ���ˡ�\n",
        	"wang" :	"��ʯ��������������ģ��������ϵ����Ĵ���ˡ�\n",
        	"�����":	"˭�κ����ҵ����ӣ�˭�����ҵĴ���ˡ�\n",
        	"����":		"˭�κ����ҵ����ӣ�˭�����ҵĴ���ˡ�\n",
        ]));
	
	setup();
	carry_object(__DIR__"obj/mcloth")->wear();
}

int cure_arong(object me)
{
 	 if (query("cured")){
 		command("say ��û�������㲻�÷����ˣ�");
 		return 1;
 	}
 	if (me->query_temp("marks/cured_monk")) {
 		command("say �Դ����ϴ������ι������Ѿ��ö��ˡ�");
 		return 1;
 	}
 	 	
 	if(!query("cured")) {
 		tell_object(me,"�Ϻ����°��ϵĴ�����Խ��ԽС��������ʧ�ˣ�����\n");
 		set("long","�Ϻ�����ɫ����Ŀ¶���⣬�������˵����ӣ�\n");
 		tell_object(me,CYN"
�Ϻ��и��˵��������ͷ����̫���ˣ���֪��ô����Ա�������Ҳ�и������ӣ�
��������԰����Ļ�����һ�������ܶ�ô���\n"NOR);
 		me->set_temp("marks/cured_monk",1);
 		set("cured",1);
 	} 
 	return 1;
}


void	reset(){
	
	set("cured",0);
	set("long","�Ϻ�����ɫ����Ŀ¶���⣬��ϧ�������°��ϳ��˸������ӡ�\n");	
}
