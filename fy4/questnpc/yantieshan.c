#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("����ɺ", ({ "yan tieshan", "yan" }) );
	set("gender", "����" );
	set("nickname",HIY"ɽ�����"NOR);
        set("title","��ⱦ����   ����");
        set("quality","evil");
	set("age", 47);
	set("int", 25);
	set("per", 20);
	set("str", 40);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"����˰װ����ֵ�һ������Ƥ��Ҳϸ����Ůһ����ֻ������һ���ر� 
���ӥ�����ӻ��Եú����������š�\n");
        set("force_factor", 55);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 13000000);
        set("score", -16000);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 360);
        set_skill("literate", 130);
	set_skill("dodge", 350);
	set_skill("meihua-shou", 130);
	map_skill("unarmed", "meihua-shou");
	set("chat_chance",2);
	set("chat_msg",	({
	"����ɺ����Ц�����ȣ��Ⱦƣ����찳�����ھ�һ�¶ǣ�˭���ǻ����ţ������ָ��������ӡ�\n"
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.meihai":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}
