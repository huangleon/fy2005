//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����Ʈ���ں��ϵ����ǣ����𡰺����ѡ��������֣��ͻ�¶�����ض�����΢Ц��
����Ҳ����û������ģ��ͺ���պ��˱��Ҿơ�ֻҪ����������õ����£��ں�����
�ﶼ�����ҵõ�����ľ���ɵ������Ѻ��ƾɣ�����û���ں�����ů��ʪ�ĺ���Ӵ�
��ĺ��ϴ�����������������������ζ���������������ڣ�Ů��ͷ�ϵ��ٻ�����ζ
�������ζ������ڡ������Լ��������ǵĸ���������
LONG
	   );
	set("exits", 
	   ([ 
	     "east"  : __DIR__"southsearoad"
	    ]));
       set("objects", 
          ([ 
        AREA_BAIYUN"npc/niuroutang" : 1,
            ]));
    set("indoors", "baiyun");
	set("coor/x",50);
	set("coor/y",-230);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
