inherit NPC;
#include <ansi.h>
int random_action();
int give_xinchungift();

void create()
{
        set_name(HIB "�´������ʹ" NOR, ({ "giftmaster" }) );

        set("gender", "����");
    set("nickname", HIW"����2005QQȺ��132539787����ӭ����"NOR);
        set("age", 92);
        set("long",
                HIC"    ���������ʹ��Ҳ������Ҫ����ɣ�
                \n         ask giftmaster about xinchungift 
                \n"NOR);
        set("attitude", "peaceful");
        set("str", 26);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("per", 50);

         set("chat_chance", 5);
        set("chat_msg", ({
                
                HIC"�����ʹ˵�������ڿ��Ե���������ȡ�´�����(ask giftmaster about xinchungift) ��\n"NOR  ,
             
        }) );
				set("inquiry",      ([
        
        "xinchungift" : (: give_xinchungift :),
               ]) );
        
        
        set("combat_exp", 10000);
        set("score", 0);
        setup();
        
}


int accept_fight(object me)
{       object who=this_player();
        command("say ����ò����֣������������裬����" + RANK_D->query_respect(who)+ "�Ķ��֣�");
        return 0;
}

int give_xinchungift()
{
        object gift;
        if (this_player()->query("combat_exp")<5000)
        {
                command("shake "+this_player()->query("id"));
                command("say "+this_player()->name()+"��ľ��鲻�����Ҳ��ܸ��㡣");
                return 1;
        }
        if (this_player()->query("cont_quest")<5)
        {
                command("shake "+this_player()->query("id"));
                command("say "+this_player()->name()+",������5�����񣬾Ϳ�����һ�������");

                return 1;
        }
        gift = new("/d/wiz/obj/xinchungift");
        gift -> move(this_player());
        message_vision("$N"NOR+"�ݸ�$nһ��"+gift->query("name")+"��\n"NOR,this_object(),this_player());
        this_player()->set("cont_quest",0);
        return 1;
}

int attack()
{
        
     command("say ���ˣ������ˣ����ﻹû������!");
     this_object()->remove_all_killer();
     return 0;

} 
