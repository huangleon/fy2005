inherit NPC;

void create()
{
        set_name("ɨ�׵ĵ�ʿ", ({ "taoist" }) );
        set("gender", "����");
        set("age", 19);
        set("long","���幬�ĵ�ʿ����һ���ɫ�ĵ��ۣ�����ɨ������������ɨ��ɽ·��\n");
        set("combat_exp", 10000);
        set("score", 200);
        set("class", "taoist");
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "�����ķ�": "�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
                "���幬": "���幬����ɽ�ϣ�����ʦ���Ǽ�������Ϳ�����컯�ˡ�\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "netherbolt" :),
        }) );

        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"�㬵�˵������������������������ô�����������\n",
                name()+"˵����ʦ���ǽ��춼��ɽ�ϣ����ʦ�Ϳ���ɽ�ɡ���\n"
        }) );

//        create_family("���幬", 7, "����");

        set_skill("magic", 20);
        set_skill("move", 20);
        set_skill("force", 20);
        set_skill("spells", 30);
        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("gouyee", 50);
        set_skill("taoism", 30);
        set_skill("necromancy", 30); 
        set_skill("snowshade-sword",30);
        set_skill("notracesnow",30);
        
        map_skill("dodge","notracesnow");   
	map_skill("force", "gouyee");
        map_skill("spells", "necromancy");
        map_skill("parry","snowshade-sword");
        map_skill("sword","snowshade-sword");
                
        setup();

        carry_object(__DIR__"obj/sword1")->wield();
	carry_object(__DIR__"obj/tcloth")->wear();
}
