inherit SMART_NPC;
#include <ansi.h>
void create()
{
    	set_name("����", ({ "chi xu","chixu"}) );
    	set("nickname", CYN"���幬 ���� "NOR);
    	set("gender", "����" );
    	set("class", "taoist");
       	set("age", 120);
    	set("attitude","friendly");
	set("long","
һ���ɷ���ǰ�������׵ĵ�ʿ���뷢��ף�����ļ����·���һ��⻬���ۣ� 
��Ư���ڰ���У�����§�Ű����÷������һ��Ʒ��÷��������ι���ļ���һ�� 
�����ɶ���׵����������⸧Ħ�� \n");
    	
       	set("combat_exp", 8000000);
    	             
	set("NO_KILL","���������ڰ��֮�У�������޷������� ��\n");
	set_temp("condition_type",WHT "<�����>" NOR);
	
	auto_npc_setup("liaoyin",350,200,0,"/obj/weapon/","fighter_w","necromancy",2);
	setup();
}

