inherit NPC;

void create()
{
        set_name("�����", ({ "dagu" }) );
        set("gender", "Ů��" );
        set("age", 38);
        set("str", 48);

        set("long","����һ����ĸߴ���üĿ�������������һ���Ů�ӡ�\n");
        set("combat_exp", 200000);
        
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 100);
        set_skill("zuixian-steps", 100);
		set_skill("iceheart",10);
        
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");

		setup();
		carry_object("/obj/armor/cloth")->wear();
}


void init()
{
        object me;
        ::init();
        me = this_player();
        if( interactive(me))
        if( me->query("class") )
        if( me->query("class") != "yinshi")
            kill_ob(me);
}

