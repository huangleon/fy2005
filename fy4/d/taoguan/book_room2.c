
inherit ROOM;

void create()
{
        set("short", "����¥");
        set("long", @LONG
����¥��ɽ�������ǹ���ʦͽ����֮����һ�������С¥���͹�����ΰ��̫��
�������ϣ�ֱ������֮�ȴ��󡣶�¥�Ƕ����Ƶ�����������硢��������媵ľ�
�ң�������һ����Ⱦ�������ª���ȵ��Ϲ���һ����¯������������������
LONG
        );
        set("exits", ([ 
  		"down" : __DIR__"book_room1",
  		"up": 	__DIR__"book_room3",
	]));
        set("objects", ([
		__DIR__"obj/desk2" : 1,
		__DIR__"npc/taolord1" : 1,
		
 	]) );

	set("no_lu_letter",1);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",15);
	setup();
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

