inherit NPC;

void create()
{
        set_name("��ͷ��ʦ��", ({ "hair oldman" }) );
        set("gender", "����" );
        set("age", 63);
        set("long", "һ���ڹ���С����������ͷʦ�����������۱��Ѿ��Եĺ�������\n");
        set("combat_exp", 400000);
               
	set("attitude", "friendly"); 
        set("chat_chance", 1);
        set("chat_msg", ({
		"��ͷ��ʦ������˫�ۣ�����ظ��׷ɷ������������㷢��\n",
        }) );
        set("inquiry", ([
                "��ͷ" : "�ţ���ͷ������ȥ����������º����Ұ������ᡣ\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
