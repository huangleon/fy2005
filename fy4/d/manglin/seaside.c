//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
        set("short", "�Ϻ���ͷ");
        set("long", @LONG
�������Ϻ�������ͷ��������ĺ���ͣ���ڴˣ������������������ַǷ���
�ܶ�����æ�������ϰ��˻����Щ���ｫ�ᾭ��·����ȫ������ۿڣ�����Զ��
����
LONG
           );
        set("exits", 
           ([ 
 	     "west"  : __DIR__"beach2",
	    ]));
	
	set("objects", 
	   ([ 
	     AREA_BAIYUN"npc/oldfox" : 1,
	     AREA_BAIYUN"npc/sailor" : 5,
	    ]));
        set("outdoors", "baiyun");
	set("coor/x",80);
	set("coor/y",-250);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}