//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "����С·");
	set("long", @LONG
���������ϣ���������������б��·���Ե�é�ݽ���ϡ�裬��ľ����������ľ��
Խ�ߵ�·Խ������������ȥ��ȻҪ�ߵ������ȥ�ˡ���ç��������ë����Ȼ�Ľ���
�ƺ�Ҳ�����������ˡ�
LONG
	   );
	set("exits", 
	([ 
	     "northdown" : __DIR__"edge4",
	     "south" : __DIR__"plainroad",
	    ]));
	set("outdoors", "baiyun");
	set("coor/x",60);
	set("coor/y",-210);
	set("coor/z",10);
	setup();
}
