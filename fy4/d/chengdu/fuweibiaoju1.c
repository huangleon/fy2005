// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����ھ�");
        set("long", @LONG
һ��������ΰ��լ��֮ǰ����������ʯ̳�и���һ���������� ����ˣ�
�˶�Ʈ�����졣�������ϻ�ɫ˿������һͷ������צ����̬���͵���ʨ��
���������չ���Ե���ʨ��������������ʨͷ����һ�Ժ�˿���������
չ����衣������������ �������ھ֡��ĸ����֣������������վ��Ƿ���
LONG
        );
	set("exits",([
  		"north" : __DIR__"xidajie1",
  		"south" : __DIR__"fuweibiaoju2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}