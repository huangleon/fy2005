// TIE@FY3

#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;
void create()
{
        set_name("�̩", ({ "yang kaitai","yang" }) );
        set("title", RED "��Դ��ͨǮׯ�ϰ�"NOR);
        set("gender", "����" );
        set("age", 32);
        set("richness",5000000);
          
        set("no_arrest",1);
        set("long",
                "���ķ������������ż��ɸɾ����Ĳ��£������˾����ǿ�ճ�¯��Ӳ�����\n");
     
        set("combat_exp", 200000);
	set("attitude", "friendly");
	
	set_skill("unarmed",100);
	set_skill("changquan",100);
     	set_skill("dodge",200);
        map_skill("unarmed", "changquan");
        
        set("inquiry", ([
                "������" : "���������ֺ���ʮһ����һ��ɣ�\n",
        ]) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
	add_action("do_loan","loan");
}

void reset(){
	set("richness",5000000);
}