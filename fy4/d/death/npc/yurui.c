#include <ansi.h>
inherit NPC;

void create()
{
    	set_name("����", ({ "yurui"}) );
    	set("gender", "Ů��");
    	set("age", 21);
    	set("per", 60);
    	set("long", "������ǰ�Ǹ��輧���绨���񣬺͸�������������������һֱȢ
��������������������Ͽ���һȥ���أ������˼�ɼ���������ؾ�
���ֶ�ȥ��������������ǰΪ�ƣ������±���Ͷ�ڸ���֮�ң���������
�����˸�����Լ������Ը���������q��֮���������ǻ����κ��űߵȴ���"YEL"
(ask yurui about soup)\n"NOR);
    	set("attitude", "peaceful");
    	set("title", WHT"�������ֻء�"NOR);
    	set("inquiry",	([
    		"soup":	"�������ŵ��q��֮�������������ŵ�ʱ�������ܹ��߹�"YEL"�κ���"CYN"�ˡ�\n",
    		"*":	"action����ָָ"WHT"����"CYN"���Ƶ�����һ�ˣ�̾�˿�����\n",
    	]));
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	CYN"
�������ĵ�˵������������
		������Լ�����ꡣ
		˭����ʮ��������
		�κ����ϵ����ꡣ\n"NOR,        	
    	}) );
    	
    	set("combat_exp", 2000);
    	set("no_arrest", 1);
    	
    	setup();
    	carry_object("/obj/armor/ghost_cloth")->wear();
}

int is_ghost(){	return 1;}
	