// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Ӫ��");
        set("long", @LONG
����Ӫ�ڶ�Ӫ�����ɰ˿��С���ߴ���ȫ��ͬ�����ο�����ɡ�����
�Ļ��֣�����ͳһ�Ľ���ʩ�����ڲ�����ĵ����ϣ�ʹ�û���Ӫ�ķ��ݷ�
�䡢ʹ�á�������ʩ��Ϊ������Ӫ�ķ�����Ŀ��ȫ��ȡ�
LONG
        );
	set("exits",([
  		"west" : __DIR__"caochang1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}