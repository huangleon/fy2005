

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "�ؽ���"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

һ�仨Ҳ��һ��������
���Ƕ仨������һ˲�䣬Ҳ��������������ʱ��
һ����������������е��������б仯֮��΢������Ͼ�û���κ����ܱȵ��ϡ�

LONG);
        set("exits", ([

  "down" : __DIR__"sword"+(query("floor")-1),
  "up" : __DIR__"sword"+(query("floor")+1), 
]));
  	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",query("floor")*40);
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


