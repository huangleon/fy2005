// Tie@fy3
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "����");
  set("long",@LONG
˴��ɽׯ�Աߵ�һ�����ǣ�һ��һ���˶���Ը�߽��ĵط���һ����ª���޿���
��ª�Ĳ��һ�����˱ǵ�������Ǵ����ﴫ������ÿ�������ܻ��м��������ƾ�
��������ؤΧ���յ����ܵĻ���߷ſڴ����
LONG
  );
  	set("exits",([
        	 "east":__DIR__"shungeng",
               ]));
    	set("outdoors", "jinan");
        set("coor/x",-30);
        set("coor/y",80);
        set("coor/z",0);
	setup();
}