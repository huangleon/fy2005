// dtz.c

inherit NPC;

void create()
{
        set_name("��ͽ��", ({ "young rogue","rogue" }) );
        set("gender", "����" );
        set("age", 32);
        set("long", "һ��ɫ���Եĵ�ͽ��.\n");

        set("combat_exp", 4000);
        set("attitude", "heroism");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
	set_skill("dodge", 50);
        set("chat_chance", 2);
        set("chat_msg", ({
                (:random_move :),
	"��ͽ�ӵ�����˵ǧ�����Ӱﵱ��͢����һ���󰸡�\n",
	"��ͽ�ӵ����ҳ��ɵ����Դ�����Ϲ�֣�û��һ��׼�ġ�\n",
        }) );

        set("inquiry", ([
                "��" : "�����ȻʵĴ̿ͱ�ͬ��ıɱ��ʬ��ǧ������ֻ�ô̿͵�ͷ�ǾͿ��������̿͵���ߣ�\n",
                "case" : "�����ȻʵĴ̿ͱ�ͬ��ıɱ��ʬ��ǧ������ֻ�ô̿͵�ͷ�ǾͿ��������̿͵���ߣ�\n",
        ]) );

	setup();
        carry_object("/obj/armor/cloth")->wear();
        
}

