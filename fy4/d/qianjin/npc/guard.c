inherit NPC;
 
void create()
{
        seteuid(getuid());
        set_name("�����", ({"boater", "boat guard",}));
        set("long",
                "һ����ѬѬ�Ĵ���ġ�\n");
        set("gender","����");
        set("combat_exp", 500000);
        set_skill("unarmed", 100);
        set_skill("changquan",120);
        map_skill("unarmed","changquan");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}