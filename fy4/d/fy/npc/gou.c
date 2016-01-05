inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("������", ({ "sai boya","sai" }) );
        set("gender", "����" );
        set("age", 31);
        set("title", CYN"��ӹ����"NOR);
        set("long","��λ�ϰ屾�������ɣ�ȴƫ��ϲ����ӹ���ţ���������
����Ц��Ϊѩ�ܾ����������Ų��ڷ��Ƴ��п������С�\n");
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([  
                "/obj/music/qixianqin"          : 40,
                "/obj/music/yaoqin"                     : 10,
                "/obj/music/erhu"                       : 30,
                "/d/biancheng/npc/obj/erhu"     : 40,
                "/obj/music/music_bihai":		40,
                "/obj/music/music_qingxin":		40,
                "/obj/music/music_shimian":		40,
                "/obj/music/music_xiaoxiang":	40,
        ]) );
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (!random(4))
                message_vision("$Nҡͷ���ԵĿ������е�һ�����ף�ȴû�����������÷��ˡ�\n",this_object(),ob);
        else if (!random(4))
                message_vision("$N��ɫ����Ķ�$n�����������ϣ�������ľ��ˮ�����������֪����\n",this_object(),ob);
        else if (!random(4))
                message_vision("$N�ӱǿ������һ��˵��������ʲô�������ұ����ɼ��ֹ��Ӷ����ֿɱ���������ˡ�\n",this_object(),ob);
        else if (!random(40) && !query("sec"))
        {
                set("sec",1);
                tell_object(ob,"������������Ķ��ߣ�С��˵������������һ�����ܣ���˵��������\n����������Ǹ��ȣ����������õö�Ĺ��١���");
        message("vision", "����������"+ob->name()+"��������˵�˼��仰��\n", environment(ob), ob);
        }
        return;
}

void reset()
{
        set("vendor_goods", ([
                "/obj/music/qixianqin"          : 40,
                "/obj/music/yaoqin"             : 10,
                "/obj/music/erhu"               : 30,
                "/d/biancheng/npc/obj/erhu"     : 40,
                "/obj/music/music_bihai":		40,
                "/obj/music/music_qingxin":		40,
                "/obj/music/music_shimian":		40,
                "/obj/music/music_xiaoxiang":	40,
        ]) );
}

