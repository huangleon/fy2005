// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��͢����Ӫ����");
        set("long", @LONG
����Ӫ��ר�Ų��ݻ����ľ��ӡ�����Ӫ�ֱ�ʱѵ����������ǹ��
��֮�⣬�����ݲ��䡢���估����ա�������ǻ���Ӫ�Ĵ��ţ����
�ŵ��������һָ�����΢�ţ������ڴ����ȵ��������������ŵ�����
����������ָ���ݷ𷢳����ߡ���һ�������Ǿ����������ػ��񡸺߹�
�������� 
LONG
        );
	set("exits",([
  		"south" : __DIR__"caochang1",
  		"northwest" : __DIR__"dongdajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}