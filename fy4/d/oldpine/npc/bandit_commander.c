#include <ansi.h>

inherit NPC;
void create()
{
        set_name("���ϴ�", ({ "boss chang","boss","chang"}) );
        set("title", "����կկ��");
        set("nickname", "�÷絶��");
        set("gender", "����");
        set("age", 53);
        set("combat_exp", 260000);
        
        set("bellicosity", 6000);
        set("attitude", "aggressive");

        set_skill("force", 60);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("dodge", 70);

        set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/parry", 100);
		set("no_arrest",1);
        setup();

        carry_object(__DIR__"obj/glaive")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();
        carry_object(__DIR__"obj/bamboo_pipe");
}


void die()
{
         object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        if (me)
        if(me->query_temp("quicksand/route_bandit") == "����կ")
        {
                me->set_temp("quicksand/route_notice",1);
                me->delete_temp("quicksand/route_bandit");
                tell_object(me,WHT"\n��ϲ��ƽ��������կ�ķ˻�!\n"NOR);
                tell_object(me,WHT"�����ȥ����С���������Ϣ�ˡ�\n\n"NOR);
        }
        ::die();
}