inherit ROOM;

void create()
{
	set("short", "����԰");
	
        set("long", @LONG
�����������������ܾ��Ǵ���԰��������������ÿ�������°׵���ҹ������
ɽׯ�����������Ǳ�����ˣ�һ�����Σ�һ����裬���Ǻ��˰������������ϧ��
���ܾ��Ѿ�û��������ˣ����ǻ�ʱ���������ֵ��ǿ�����Ǯ���ƣ��긴һ�꣬��
��԰�е�����ҲԽ��Խ�٣�
LONG);

	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"south":__DIR__"wuzhuxuan",
	]) );
        set("objects" , ([
        	__DIR__"obj/bspear" : 2,
        ]));

	set("coor/x",-10);
	set("coor/y",220);
	set("coor/z",80);
	setup();
}

void reset(){
        object item;
        int i;
        ::reset();
      
	if(!present("bamboo spear", this_object())){
                for (i=1; i<=2 ; i++) {
                	item = new(__DIR__"obj/bspear");
	                if(objectp(item)){
                        item->move(this_object());
                	}
	        }
        }
        return;
}          