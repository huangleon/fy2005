// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("��Ա��", ({ "jia" }) );
	set("gender", "����" );
	set("title","һë����");
	set("age", 47);
	set("long", "��Ա�����Լ���С����������������Ժ�����Ͳ������˽��룬
���±���͵���Ķ�������Ա����̬ӷ�ף������Ͼ����ǿ��˹����Ƶġ�
�������ܸߣ������е��ձ���\n");
	
	    set("inquiry", ([
        	"����" : 	"����û�е���������������������ҡ�\n",
        	"yubotao" : "����û�е���������������������ҡ�\n",
        	"��ʯ��" : 	"��ʯ��������������ģ��������ϵ����Ĵ���ˡ�\n",
        	"wang" :	"��ʯ��������������ģ��������ϵ����Ĵ���ˡ�\n",
        	"�����":	"�������ҵĶ��˲��٣���ϧ�������ˡ�\n",
        	"����":		"�������ҵĶ��˲��٣���ϧ�������ˡ�\n",
        ]));
	
	
	set("combat_exp", 30000);
	setup();
	carry_object(__DIR__"obj/jcloth")->wear();
}

int cure_arong(object me)
{
 	if (query("cured")){
 		command("say ��û��û������Ϲæ��ʲô��");
 		return 1;
 	}
 	if (me->query_temp("marks/cured_jia")) {
 		command("say �Դ����ϴ������ι������Ѿ��ö��ˡ�");
 		return 1;
 	}
 	
 	if (!me->query_temp("marks/cured_monk")) {
 			command("say ��������������������鲻�鰡������ҵ�����Ʒ��");
 			tell_object(me,"��Ա�ⲻԸ���������ơ�\n");
 			return 1;
 	}
 	
 	tell_object(me,"��Ա�ⱳ���ϵĴ�����Խ��ԽС��������ʧ�ˣ�����\n");
 	tell_object(me,"��Ա����˵ص���̫���ˣ��������ҵĴ����ѽ��\n");
 	me->set_temp("marks/cured_jia",1);
 	
 	command("say �������������㵽�Ҽҵ���Ժȥ���棡\n\n\n");
 	
 	set("long","��Ա�����Լ���С����������������Ժ�����Ͳ������˽��룬
���±���͵���Ķ�������Ա����̬ӷ�ף������Ͼ����ǿ��˹����Ƶġ�\n");
 	
 	set("cured",1);
 	return 1;

}



int	reset(){
	set("cured",0);
}

