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
		  "northup" : __DIR__"palace_path5",
		  "east" :  __DIR__"troad0",
	])); 
	set("outdoors","tieflag"); 	
	
	set("coor/x",260);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}
