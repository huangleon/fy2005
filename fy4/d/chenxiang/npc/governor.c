// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int leave();
void create()
{
        set_name("¬����", ({ "master lu", "master","lu" }) );
        set("long",
                "��͢��פ�ڳ������Ʒ֪�أ���ʿ����������Ϊ����ó�����հ�����\n");
		set("nickname", HIG"ֱ���¸�"NOR);
        set("attitude", "heroism");
        set("class","official");
        set("group","officer");
        set("rank_nogen",1);
        create_family("��͢����",7,"�������� ֪������");
 
    	set("student_title","��Ա");
    	set("ranks",({ "׼����","����","����","��ͳ��","ͳ��","��Ӫ��ͳ��",
                       "��Ӫͳ��","��Ӫ��ͳ��","���������ᶼָ��ʹ","�����������ᶼָ��ʹ",
                       "�����׾��������ݺ�","�����׾�������ݺ�","��ǰ���ݺ�",
                       "�����׾�������ָ��ʹ","�����׾������ָ��ʹ","��ǰ��ָ��ʹ",
                       CYN"�����׾�������ָ��ʹ"NOR,CYN"�����׾������ָ��ʹ"NOR,HIC"��ǰ��ָ��ʹ"NOR }));
    	set("rank_levels",({ 32000,64000,128000,256000,384000,
                             512000,800000,1024000,1556000,
                             2048000,3652000,5000000,
                             6258000,8848000,10800000,
                             14580000,20048000,26244000 }));    
   	set("inquiry", ([
		"leave": (: leave :),
	]) );
        set("combat_exp", 1000000);    
	set("vendetta_mark", "authority");
	set("reward_npc", 1);
	set("difficulty", 20);
        
	set("guard_msg",HIW"$N�������컯�գ�����Ǭ���������������ھ�ɱ��͢��Ա����������\n"NOR);
	
		set_skill("unarmed", 100);
        set_skill("spear",100);
		set_skill("force",100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("changquan",150);
		set_skill("puti-steps",100);
		set_skill("yue-spear",100);
        set_skill("manjianghong",100);
        set_skill("move", 100);
    	set_skill("leadership",100);
    	set_skill("strategy",100);
    	set_skill("literate",100);
    	set_skill("foreknowledge", 100);
    	
		map_skill("unarmed","changquan");
		map_skill("dodge","puti-steps");
        map_skill("force","manjianghong");
		map_skill("spear","yue-spear");
		map_skill("parry","yue-spear");
        
        set_temp("apply/damage",500);
        setup();
        carry_object(__DIR__"obj/guanfu")->wear();
}

void attempt_apprentice(object me)
{
	if( !me->query("class"))
	{
		command("smile");
		command("say �ܺã���͢��������֮ʱ��Ŭ���ɣ�\n");
        	command("recruit " + me->query("id") );
	}
	else
		command("say ��͢����Ҫ�����ֲ������ģ���������֮�ˣ�\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "official");
		ob->set("vendetta_mark", "authority");
	}
}


void init()
{	
	::init();
	add_action("do_killing", "kill");
    
}


int leave() {
	if (this_player()->query("class")!="official") return 0;
	message_vision(CYN"$N��ɫ��������Ч��͢���Ҿ�����֮�£���ô�ܰ�;�����ء���\n"NOR, this_object());
	message_vision(CYN"$N˵����ִ��Ҫ����Ҳ����ǿ��ֻ�ǴӴ˾���һ��ƽ�񣬳�֮͢����Ҳ��Ȩ���ʡ�\n"NOR,this_object());
	message_vision(CYN"$N˵����ԧ��ȭҲ������ʹ����˼����˼��\n"NOR,this_object());
	return 1;
}

