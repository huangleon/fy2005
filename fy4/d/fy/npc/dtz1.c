inherit NPC;
int tell_him();
void create()
{
        set_name("��������", ({ "bored youngster","youngster" }) );
        set("gender", "����" );
	set("title","���ֺ��е�");
        set("age", 19);
        set("long", "һ�����ֺ����������µ������ˡ�\n");

        set("combat_exp", 4000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
	set_skill("dodge", 20);
        set("chat_chance", 1);
        set("chat_msg", ({
                (:random_move :),
	"�������������˵���һ����ʨ�ھֵ���ʦ�õ��˿ڱ����������ޱȣ������Ǽ���
�������������� ��ͷ����ȥ����һ�¡�\n",
        }) );
    	set("inquiry", ([
	        "����" : (: tell_him :),
	        "sword" : (: tell_him:),
	        "��ʦ" : (: tell_him :),
	        "biaoshi" : (: tell_him:),
        ]));
	setup();
	add_money("coin", 1);
        carry_object("/obj/armor/cloth")->wear();
        if (!random(2))
		carry_object(__DIR__"obj/jade_sword");
        
}
int tell_him()
{
    	object me;
    	me =this_player();
    	tell_object(me,"�������������һ�ۣ������Ǹ�����ඡ�����\n");
    	if (!REWARD_D->riddle_check(me,"ʧ���粨") && !REWARD_D->check_m_success(me,"ʧ���粨"))
    		REWARD_D->riddle_set(me,"ʧ���粨",1);
    	return 1;
}
