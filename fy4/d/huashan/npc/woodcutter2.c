// woodcutter.c
inherit NPC;
int milin();
void create()
{
        set_name("���Է�", ({"woodcutter"}) );
        set("gender", "����" );
        set("age", 66);
        set("agi",30);
        set("per", 10);
        
        set("long",
		"һ��������Է����ڳ���Ŀ���ʹ������һ˫�ֲ������ϼ롣\n"
		);
        set("combat_exp", 200000);
	set("inquiry", ([
			"milin" : (: milin :),
			"����" : (: milin :),
			"����" : (: milin :),
		]));
        set_skill("move", 250);
        set_skill("parry", 200);
	set_skill("dodge", 260);
        set_skill("axe",200);
	setup();
	carry_object("/obj/weapon/woodaxe")->wield();
	carry_object("/obj/armor/cloth")->wear();  
}

int milin(){
	object me;
	me = this_player();
	message_vision("$Ņͷ����$nһ�۵�������Ƭ��������Ҳ�߲�����ÿ�ζ�ת�ص�����ҿ�Ҳֻ��
��ɵ����֪�����ֺ�����ʲô��\n", this_object(), me);
	return 1;
}

