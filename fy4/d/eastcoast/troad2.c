inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
����Ĺ�ľ������Щ������ʹ��ֲ���ǰ���ĵ�·��һ��С�ľͱ���֦�ҵ���
�ֽţ���ǰ���ֲ�֪ͨ������㲻������������֮�ġ�
LONG                                         
        );
        set("exits", ([
		  "south" : __DIR__"troad1",
		  "west" :  __DIR__"troad3",  
		  "east" :  __DIR__"troad4",
	])); 
	set("outdoors","tieflag"); 	
	
	set("coor/x",610);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}