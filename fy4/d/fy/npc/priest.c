// keeper.c

inherit NPC;

void create()
{
        set_name("�̸�", ({ "priest" }) );
        set("gender", "����" );
        set("age", 74);
        set("long","������˽𷢱��ۣ��������߳߶�ߡ�\n");
        set("combat_exp", 1);
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
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "�̸�˵������λ" + RANK_D->query_respect(ob)
                + "�����ᱣ����ģ�\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = (int) ob->value();
        if( val > 100 ) {
                if( ((int)who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - (random((int)who->query("kar")) + val/1000) );
        }
        say( "�̸�˵������л��λ" + RANK_D->query_respect(who)
                + "����һ���ᱣ����ġ�\n");

        return 1;
}
 

