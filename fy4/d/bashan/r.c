
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
����ʯ�ƵĴ��ź���һ���޳�������������΢���Ĵ��÷��ӹ���������
�������ϵ����£�����һ˿һ����ѹ�֡��������ǽ��ÿ�������Ͳ���һ֧ţ��
����ӳ�ú�ʯ�������������
LONG
        );
	set("exits",([
  		"east" : __DIR__"jadegate",
  		"enter" : __DIR__"couplemaze_24",
	]) );
	set("no_fly",1);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

