inherit NPC;
void create()
{
        set_name("С����", ({ "xiao ximen", "ximen"}) );
        set("title", "���Ŵ�ѩ֮��");
        set("gender", "����");
        set("age", 3);
        set("long",
"���Ŵ�ѩ���ǵ�����������֮һ�������Ѿ������ˣ��޽����ľ��磮��
��Ȼ�������Ӻ�С����û�кܸߵ��书��\n"
               ); 
        set("attitude", "peaceful");
        set("combat_exp", 5000);
        set("chat_chance", 10);
        set("chat_msg", ({
                "С����ָ�ű���˵����½�����������Ǳ����ˣ�����\n",
        }) );
        setup();
	carry_object(__DIR__"obj/cloth2")->wear();
}
