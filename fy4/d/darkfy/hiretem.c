inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������ʪ���ƾɲ�����ÿ����紵������������ҡ�Σ��ƺ����Ͼͻᵹ��������
һ֧�����ڷ���ҡҷ����������������ɭɭ���������ﲼ���ҳ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west"  : __DIR__"nwind5", 
]));
        set("coor/x",5);
        set("coor/y",50);
        set("coor/z",-300);
        setup();
}


