// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;

#include <ansi.h>
int init_quest();

void create()
{
    set_name("����", ({ "dai yin","dai"}) );
    set("title", "ؤ���������");
    set("gender", "����" );
    set("age", 34);
    set("attitude","friendly");
    set("class","beggar");
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
	(: perform_action, "unarmed.xianglongwuhui" :)
      }) );
      
     set("inquiry", ([
        "�������":	(: init_quest :),
        "����":		(: init_quest :),
     	"Ԭ��":		"Ԭ�����岨�������ǿ�������\n",
     	"���ɢ":	"�������й©������ȥ���˴��¡�\n",
     	"ƭ��":		"�ȣ������ϱ���������ƭ����ƭ�㣬����������ؤ��������֮ʦ��
�ǽж��ǲ�������\n",
		"��ҩ���ϰ�":	"������Զ�����塣\n",
     ]));  
      
    set("combat_exp", 250000);
    set_skill("move", 100);
    set_skill("parry",100);
    set_skill("dodge", 100);
    set_skill("force", 100);
    set_skill("literate", 80);
    set_skill("unarmed",100);
    set_skill("doggiesteps",80);
    set_skill("dragonstrike",80);
    set_skill("huntunforce",80);
    set_skill("begging",120);
    map_skill("dodge", "doggiesteps");
    map_skill("force", "huntunforce");
    map_skill("unarmed", "dragonstrike");
    setup();
    carry_object(__DIR__"obj/5bagcloth")->wear();

}

int	init_quest(){
	object me= this_player();
	
	if (REWARD_D->riddle_check(me,"���ȵ��")!= 7
		&& REWARD_D->riddle_check(me,"���ȵ��")!= 8)
		return 0;
		
	tell_object(me,CYN"
�������ĵ�˵������ֻ����ȡ���������ᡣ

����˵��С����һ�常���Ǵ˵�ҩ���ϰ壬��������˵�����ɢ��һҩ��
����ȥ�����̾��������ǹ������컹�ܸ��������Ԭ�����˴�ҩ������
ƭ������֮�ˣ��Ż������ȳ���\n"NOR);
	REWARD_D->riddle_set(me,"���ȵ��",8);
	
	return 1;
}

