// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����˼�");
        set("long", @LONG
ǧ��¥�ɶ��ֵ�--�����˼䡣 һ���ţ����߶���������ӡ�Ժ�е�ļ���
ɽʯ��һ�����������Ž�����һ������һ���������ģ�������ɡ��˿�����ƣ�
���µ�ɰ������Ժ�主���ûʣ�Ӻ�ݻ����ſڸ߹�һ�����ͽ��ң�
		�����˼�
LONG
        );
	set("exits",([
  		"west" : __DIR__"nandajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}