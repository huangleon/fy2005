// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ĳ�");
        set("long", @LONG
�����ӵĶ��ӣ���С�����ڳɶ�����С�ĳ������������ǽ�̻Իͣ�
�ûʸ���������̨���Ǵ����ģ������ֵط�����ǧ���˰������ӣ�û��
�����ԩ��������������˴��СС�Ķ�����ֻҪ��˵�����õĶľߣ�
���ﶼ�С����ң�����һ�顣
LONG
        );
	set("exits",([
  		"east" : __DIR__"beidajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}