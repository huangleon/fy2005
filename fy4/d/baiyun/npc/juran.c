#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("ɮ��Ȼ", ({ "monk juran","juran" }) );
        set("gender", "����" );
        set("title", "��ɮ");
        set("nickname",HIC"�嶥Ϧ���̼�ˮ������������Ȼɽ"NOR);
        set("age", 32);
        set("class","moon");
        set("long", 
"ɮ��Ȼʦ�ж�Դ����ī���󣬶໭����������ó������壬���Ʊʽ�ī��̦��\n��֮��Դ��Ϊ�������ݡ�Ϊ��ʱ���ɻ��ҵĴ���֮һ��\n");
        set("combat_exp", 10000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "ɮ��Ȼ����һЦ��������Ƶ����ν�˼��ɾ����ٶ�ı�ī��Ҳ�޷�����һ�����ϣ���ϧ��ϧ��\n",
		}) );
        set("attitude", "friendly");

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_u","stormdance2",1);

        setup();
        carry_object(__DIR__"obj/sengyi")->wear();
}
int accept_fight(object me)
{
        command("say �������գ�Сɮһ�黭����ʩ�����붯�˸ɸ��أ�\n");
        return 0;
}
/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
