// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���й㳡");
        set("long", @LONG
�ɶ���ʷ�ƾã��С��츮֮�����������н��ϡ����������պ��������ơ��ɶ�
���÷���Ļ����٣����ʢ�С��˵ؽ�����ΰ׳�ۣ��ֵ�ƽ̹����������
֮�ڰٻ��Ƽ���������Ŀ���ٵ�֮������������������Ϣ�������쳣������
Ҳ������ˣ�һЩ������������ë��Ҳ�ۼ��ڡ�
LONG
        );
	set("exits",([
  		"west" : __DIR__"xidajie1",
  		"east" : __DIR__"dongdajie1",
  		"north" : __DIR__"beidajie1",
  		"south" : __DIR__"nandajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}