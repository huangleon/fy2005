// beggar.c

inherit NPC;

void create()
{
        set_name("ˮ��", ({ "shuishou" }) );
        set("gender", "����" );
        set("age", 23);
        set("long", "һ�����ڰڰ����ӣ��Բ������ǧ��¥��ū��\n");
        set("combat_exp", 20000);
        set("str", 27);
	set("attitude", "friendly");
        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
		"ˮ������Ц��Ц��������֣�����������Ҫ��Ǯ��\n",
        }) );
        
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"����һ�����������Ŀ��ĵģ�");
        return 1;
}
