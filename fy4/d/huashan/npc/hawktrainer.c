// hawktrainer.c
#include <ansi.h>
inherit SMART_NPC;
void followhim(object ob);
int jice();

void create()
{
        set_name("ѱӥ��", ({ "hawk trainer","trainer" }) );
        set("gender", "����" );
        set("age", 34);
        set("long", "�����ϴ��Ÿ���ֵ����֣����Ż��������è��\n");

        set("class","wolfmount");
        set("inquiry", ([
                "hawk": "��ұ����ƭ�ӣ������ͷӥ���ǲ�������\n",
                "��ӥ": "��ұ����ƭ�ӣ������ͷӥ���ǲ�������\n",
                "��ұ��": "��ұ����ƭ�ӣ������ͷӥ���ǲ�������\n",
                "ѱӥ":  "��˵��ұ����ѵ��(train)���֣������������ķ�������ô�����ɡ�\n",
                "train":  "��˵��ұ����ѵ��(train)���֣������������ķ�������ô�����ɡ�\n",
                "ѵӥ": "��������ѱӥ����ѵӥ��\n",
        
                "����": (: jice :),

        ]));    
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(40) :),
        }) );

    
        set("combat_exp", 7000000);
        set("attitude", "friendly");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "ѱӥ��˵������ѱ�ò�ӥ��ʲô���˶��Ӳ������ģ�\n",
        }) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/eyecover.c")->wear();
        carry_object(__DIR__"obj/leathersleeves.c")->wear();

        auto_npc_setup("wang",300,220,0,"/obj/weapon/","fighter_w","assassin-hammer",1);

}

void init()
{
        object ob;
        ::init();
        if(interactive(ob = this_player()) && !is_fighting() && userp(ob))
        {

                if((string) ob->name() == "��ұ��" )
                {
                        
                        remove_call_out("followhim");
                        //message_vision((string) ob->name(),this_object());
                        call_out("followhim", 2, ob);
                        
                }
        }
        //add_action("do_catch","catch");
        add_action("do_kill","kill");
}


void check_status(object ob)
{
        object room;
        room = find_object(AREA_HUASHAN"fupi");

        remove_call_out("check_status");
        if (!objectp(ob) || !present(ob, environment(this_object())))
        {
                
                message_vision(YEL"$N˵����ұ����������ȥ��? \n",this_object());
                message_vision("$N˵���ҵû�ȥ�����ҵ���ӥ�� \n"NOR,this_object());
                set_leader(0);
                set("chat_chance", 1);
                this_object()->move("/d/huashan/fupi");
                room->delete("item_desc");
                return;
        }
        else
        {
                if((string) ob->name() != "��ұ��" )
                {
                        //remove_class_out("check_status");
                        
                        message_vision(YEL"$N��$n��ȵ����㲻�ǹ�ұ������ ������������ƭ�ӣ���\n", this_object(),ob);
                        message_vision("�ҵû�ȥ�����ҵ���ӥ�� \n"NOR,this_object());
                        set_leader(0);
                        set("chat_chance", 1);
                        this_object()->move("/d/huashan/fupi");
                        room->delete("item_desc");
                        return;
                }
        }
        message_vision("$N��$n�������ұ�������Ұ����ķ���ѵ���ˡ�����ӥ���ǲ��������������ٸ�ָ��ָ��ɣ�\n",this_object(),ob);
        call_out("check_status",10,ob);
        return;
}


void followhim(object ob)
{
        object room;
        room = find_object("/d/huashan/fupi");
        if(environment() == room)
                if( present(ob, environment()))
                {       
                        message_vision( HIY"ѱӥ��һ����$N����ϲ����������ұ���������������ˣ����ٸ�ָ��ָ��ɣ���\n"NOR,ob);
                        set_leader(ob);
                        set("chat_chance", 0);
                        call_out("check_status",10,ob);
                }       
}


int do_kill(string arg)
{
    if (arg == "hawk" || arg=="��ӥ")
    {
        message_vision(RED"$N��$n���һ�����������ӥ�����⣡���ò��ͷ��ˣ� \n"NOR,
                       this_object(),this_player());
        this_object()->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
    }
    return 0;
}


int jice()
{
        object me,hawk;
        me = this_player();
        hawk = present("big hawk",environment());
        if ( REWARD_D->riddle_check(me,"��������") < 5 
        	&& !REWARD_D->check_m_success(me,"��������"))
                return 0;
        if (!hawk)
                return 0;
        if (REWARD_D->riddle_check(me,"��������") == 5)
                REWARD_D->riddle_set(me,"��������",6);

        ccommand("stare");
        ccommand("say "HIR"���Ȼ֪���ˣ��������ٻ���ȥ��"NOR);
        kill_ob(me);
        hawk->kill_ob(me);
        return 1;
}

void die()
{
        object suu;
        suu = present("big hawk",environment());
        if (query_temp("last_damage_from"))
        if (REWARD_D->riddle_check(query_temp("last_damage_from"),"��������") == 6 || REWARD_D->check_m_success(query_temp("last_damage_from"),"��������"))
             if (suu )
            {
                ccommand("emote �����Ŵ�У�С����ȥ������ȥ������");
                message_vision(HIC"\n��ӥ�������������ԣ�������˫�ᣬ���ų����巽���ȥ��\n\n"NOR,this_object());
                destruct(suu);
                suu = new(__DIR__"obj/lingbai");
                suu->move(this_object());
        	}
        ::die();
}

