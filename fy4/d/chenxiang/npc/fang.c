#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("������", ({ "fang longxiang", "fang" }) );
        set("long",
                "����������ϰ壬�۽����������ƣ����۾�ȴ����ѩ����һֻ����װ\n�˸������ӡ�\n");
    	set("nickname", HIC"��������"NOR);
        set("title", "������ �ֶ����");
    	
    	set("class","huangshan");
    	set("chat_chance",1);
	set("chat_msg",	({
        "�����㳯�ݺ�Ļ�԰��������������������ӥ��ʲô��������ʲô\n�ʸ�������������Ǽ����鱦��\n",
			})  );
        set("inquiry",([
        "��ȸ��"  :"��˵���µİ���һ����������\nʮ���֣����Դ������а�����������ȸ��������������ɹ��������\n��һ�֡�\n",
		]) );
        set("combat_exp", 1000000);
	
	set_skill("sword",100);
	set_skill("move", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",100);

        set_skill("yunwu-strike", 120);
        set_skill("siqi-sword", 120);
        set_skill("xianjing", 120);
        set_skill("liuquan-steps", 120);

        map_skill("unarmed", "yunwu-strike");
        map_skill("sword", "siqi-sword");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");

		set("perform_unarmed_attack", "huangshan/dodge/liuquan-steps/liushuichanchan");
	
		set("chat_chance_combat", 20);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );


	setup();
        carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/hook")->wield();
}
