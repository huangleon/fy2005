#include <ansi.h>
#include <combat.h>
inherit WALL;

void create()
{
	set_name("����֮ǽ", ({ "wall of blossoms","wall" }) );
	set("race","Ԫ��");
	set("long","��������ļ��ٹ��������ǽ�ڣ�ǽ��ÿ֦����ÿƬҶ��\nÿ��궼��ȷ����ͬ��\n");
	set("combat_exp",0);
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);


	set_skill("iron-cloth",200);
	set_skill("steelwall",200);
	map_skill("iron-cloth","steelwall");
	setup();
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
