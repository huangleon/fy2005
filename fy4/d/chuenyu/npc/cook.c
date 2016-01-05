// butcher.c

inherit NPC;

void create()
{
        set_name("����", ({ "cook" }) );
        set("gender", "����" );
        set("age", 35);
        set("long", "�㿴��һ��С���ӣ� �����ñ�������ǡ�\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 20000);
        set("attitude", "heroism");
        set_skill("dagger", 100);
        set_skill("parry", 100);
        set_skill("dodge", 150);
        set("inquiry", ([
                "С��" : "��Ҫ������ȥ�ҡ�",
                "����" : "��Ҫ������ȥ�ҡ�",
                "���ڻ�̫" : "��Ҫ������ȥ�ҡ�",
                "����" :"��Ҫ������ȥ�ҡ�",
        ]) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/bknife")->wield();
        carry_object(__DIR__"obj/qiwine");
        carry_object(__DIR__"obj/pigmeat");
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                 say( "��������ţ������ǵģ��������ڵ�����������������\n");
                    break;
                case 1:
                        say( "���ӵ�����ȥ���νб��������Է���\n");
                        break;
        }
}

 
