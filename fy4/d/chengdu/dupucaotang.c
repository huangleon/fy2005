// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���Ҳ���");
        set("long", @LONG
�Ÿ���ܰ�ʷ֮���������ɶ�,�����˵İ����¸���������é�ݣ�������
ʫ���ᵽ��"��������լ���ٻ�̶��ׯ"�ĳɶ����á��������ľ���죬÷��
���֣�Ϫˮ���ѣ���ͤ��䣬�������ţ�����ͨ�ģ�԰�ָ�ֵ��Ŷ�������
�����ǶŸ��������ڳ���������������д��������Ҷ
LONG
        );
	set("exits",([
  		"west" : __DIR__"beidajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}