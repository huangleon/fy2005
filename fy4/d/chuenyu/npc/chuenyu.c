#include <ansi.h>
inherit NPC;

string kill_passenger(object who);

void create()
{
        set_name("���ڻ�̫", ({ "chunyu" }) );
        set("gender", "����" );
        set("title", "���ڱ���");
        set("age", 47);
        set("str", 27);
        set("int", 12);
        set("per", 10);
		set("max_kee", 2000);
        set("long", @LONG
���ڻ�̫��ǿ����������ʱ��ҽ��ᣬ�޶�����������
�Զ��磬û��Ը����Ϊͽ�������������������ټ�֮������
��һ��
LONG
);
        set("attitude", "killer");
		set("reward_npc", 1);
		set("difficulty", 2);
        set("no_arrest",1);
        set("combat_exp", 80000);
        set("bellicosity", 3000 );
        set("chat_chance", 50);
        set("chat_msg", ({
"���ڻ�̫�ȵ���߾���㾹�һ���ү�ĺ��£�\n",
         }) );
        set_skill("unarmed", 60);
        set_skill("whip", 30);
        set_skill("dodge", 40);
        set_skill("parry", 30);
        set_skill("snowwhip", 80);
        set_skill("bai-quan", 20);
        set_skill("pyrobat-steps", 100);
        
        map_skill("whip", "snowwhip");
        map_skill("unarmed","bai-quan");
        map_skill("dodge", "pyrobat-steps");
        set("score", 100);

        setup();
        
        carry_object(__DIR__"obj/chwhip")->wield();
        carry_object(__DIR__"obj/cundan");
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("���ڻ�̫�ȵ���߾���㾹�һ���ү�ĺ��£�\n",ob);
                kill_ob(ob);
        }
}

void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
		} 
        if (me)
        if(me->query_temp("quicksand/route_bandit") == "���ɱ�")
        {
                me->set_temp("quicksand/route_notice",1);
                me->delete_temp("quicksand/route_bandit");
                tell_object(me,WHT"\n��ϲ��ƽ���˺��ɱ��ķ˻�!\n"NOR);
                tell_object(me,WHT"�����ȥ����С���������Ϣ�ˡ�\n\n"NOR);
        }
        ::die();
}