inherit NPC;
void create()
{
        set_name("��Ӱ", ({ "shadow" }) );
        set("gender", "����" );
        set("age", 42);
	set("str",22);
        set("long","
�������ǳմ����֮ɫ��Ŀ��Ҳ����ʧȥ�������Ĺ���
�������������Լ�����������ֱҲ�������Լ��Ǹ����ˡ�\n");
	set("combat_exp", 20000);
        set("chat_chance", 1);
        set("chat_msg", ({
		"��Ӱ����ɨ��ɨ�ŵأ�������\n",
        }) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/item/broom")->wield();

}
