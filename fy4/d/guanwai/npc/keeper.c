// keeper.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ף", ({ "keeper" }) );
        set("gender", "����" );
        set("age", 74);
        set("long","
������˿�������ʮ�����ˣ�����һ���в�֪�������˶��ٷ�����꣬���Ѿ�
���������������������飬���������͵���Ӱ�����Ȼ�������������������\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object book;
        if( !ob || !present(ob, environment(this_object())) ) return;
        if (REWARD_D->riddle_check(ob,"��������")==3)	{
		message_vision(CYN"$Nһ����˵������ү�����ˣ�����������ϲ��ã���\n"NOR,ob);
		message_vision(CYN"
��ף�Ǻ�һЦ˵�����þ�û��������ϸ��ˣ�����ͽ��ͽ�ﵹ���������
�Ȳ裬Ҳ���Ϻ������ʺã���Ϊ�㳤;���棬�Ȿ��Ҳ�����õ��š���Ȼ
���˴����¾͵��������������ط��Ƴǣ��ɴ��ӭ÷��ջ������\n"NOR,this_object());
		tell_object(ob,CYN"��ף������һ��С���ӣ�����ָ�ϣ���\n"NOR);
		tell_object(ob,CYN"
��ף���ĵض���˵���ٸ�����һ�����ϣ��ط���ǰ������ȵ������ʯ��
�����̵�"WHT"����"CYN"���������ϲ���˵������������������ء�\n"NOR);

		tell_object(ob,WHT"\n�������������˵�ʹ�����������/��������ˣ�����\n"NOR);
		book = new("/obj/item/newbie_book1");
		if (!book->move(ob))
			book->move(environment(ob));
		if (ob->query_skill("magic",1)<10)  ob->set_skill("magic",10);
		if (ob->query_skill("spells",1)<10)  ob->set_skill("spells",10);
		ob->delete_temp("marks/newbie_quest");
		ob->set_temp("marks/guanwai_mache",1);
		REWARD_D->riddle_set(ob,"��������",4);
		return;
	}
        
        say( "��ף˵������λ" + RANK_D->query_respect(ob)
                + "��������Ǯ�������°ɡ�\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("�ⶫ����ֵʲôǮ��\n");
        else if( val > 100 ) 
        {
                if( (who->query("bellicosity") > 0)&&(random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", -(random((int)who->query("kar")) + val/1000) );
        }
        say( "��ף˵������л��λ" + RANK_D->query_respect(who)
                + "������һ���ᱣ����ġ�\n");

        return 1;
}