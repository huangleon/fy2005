#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ԯ��ȱ", ({ "san que" }) );
        set("gender", "����" );
        set("age", 53);
		set("title","���۵���");
        set("long", "��ԯ���ɵ��ֵܣ��书�߾���Ϊ���ĺ�������\n");
        set("combat_exp", 4000000);
        set("reward_npc", 1);
		set("difficulty", 5);
		set("attitude", "aggressive");
        set("chat_chance", 1);
        set("chat_msg", ({
             (: random_move :),
         }) );
        set("inquiry", ([
                "��ʮһ��" : "�Ҹոմ��������ϸ���һ���⣬�����ˡ�\n",
				"xiao 11" : "�Ҹոմ��������ϸ���һ���⣬�����ˡ�\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/qin")->wield();
}
