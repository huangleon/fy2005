inherit NPC;
void create()
{
        set_name("��ϴ�ʦ", ({ "kugua dashi","kugua" }) );
        set("gender", "����" );
        set("class", "shaolin");
        set("age", 52);
        set("long", "һ����ò�������ü���׵��Ϻ��С���Ȼ��ϴ�ʦ��������������ĳ���ȴΪ
������˫�������������Ƶ���ի�����������¡�\n");
        set("combat_exp", 100000);
        set("chat_chance", 1);
        set("chat_msg", ({
    	    "��ϴ�ʦ����ն��̨���˼�Ȧ����ɫ�������԰ף���������������ս��������\n",
		}) );
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/sengyi")->wear();
}
int accept_fight(object me)
{
        command("say �������գ����������Ѹߣ���ͨ�����ʩ������Ц��\n");
        return 0;
}
